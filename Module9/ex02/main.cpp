#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 3) {
        std::cout << "Error: Min 2 numbers" << std::endl;
        return (1);
    }

    PmergeMe pm;
    PmergeMe::Pair p;

    pm.updateElm(ac - 1);
    for (int i(1); i < ac -1; i+=2) {
        int a = atoi(av[i]);
        int b = atoi(av[i + 1]);
        try {
            if (a <= 0 || b <= 0)
                throw PmergeMe::NonPositiveArgument();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            return (-1);
        }
        if (a < b) {
            p.a = a;
            p.b = b;
        }
        else {
            p.a = b;
            p.b = a;
        }
        pm.getVector().push_back(p);
        pm.getDeque().push_back(p);
    }
    std::clock_t time_before = clock();
    pm.merging(pm.getVector(), 0, pm.getVector().size() - 1);
    pm.buildChain(pm.getVector(), pm.getMainVector(), pm.getWaitVector());
    pm.insertion(pm.getMainVector(), pm.getWaitVector());
    std::clock_t time_after = clock();
    pm.updateTime(time_after - time_before, 0);

    time_before = clock();
    pm.merging(pm.getDeque(), 0, pm.getDeque().size() - 1);
    pm.buildChain(pm.getDeque(), pm.getMainDeque(), pm.getWaitDeque());
    pm.insertion(pm.getMainDeque(), pm.getWaitDeque());
    time_after = clock();
    pm.updateTime(time_after - time_before, 1);
    std::cout << pm;

    /* std::vector (rapide, contigu) :

+----+----+----+----+
| 0  | 1  | 2  | 3  |
+----+----+----+----+
   ↑    ↑    ↑    ↑
   CPU accède directement aux éléments, 
   tout est côte à côte → cache efficace

std::deque (plus lent, blocs séparés) :

Block0       Block1       Block2
+----+      +----+      +----+
| 0  |      | 2  |      | 4  |
| 1  |      | 3  |      | 5  |
+----+      +----+      +----+
   ↑           ↑           ↑
   CPU doit d’abord consulter le bloc → accès indirect, 
   plus de cache misses → plus lent*/
}