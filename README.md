# CPP Piscine — 42 C++ Modules

Solutions for 42's C++ curriculum (Modules 0 → 9), covering everything from basic C++98 syntax to STL containers, templates, and custom implementations of classic algorithms. Each exercise lives in its own folder with its own `Makefile` (`all`, `clean`, `fclean`, `re`).

> Written in strict C++98 (`-std=c++98 -Wall -Wextra -Werror`), following 42's Orthodox Canonical Form for every class (default constructor, copy constructor, copy assignment operator, destructor) unless the exercise explicitly forbids it.

## Building

Every exercise is standalone:

```sh
cd Module<X>/ex<YY>
make        # builds the binary
make clean  # removes .o files
make fclean # removes .o files and the binary
make re     # fclean + all
```

## Module overview

### Module 00 — C++ basics
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `megaphone` | argv handling, uppercasing strings |
| 01 | `phonebook` | First class (`Contact`), a fixed-size 8-contact address book with ADD/SEARCH/EXIT |
| 02 | `account` | Static members, timestamps, a bank account ledger (`Account`) |

### Module 01 — Memory allocation, references, pointers
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `zombie` | Heap vs. stack allocation (`newZombie` / `randomChump`) |
| 01 | `zombie` | Zombie hordes with `new[]` / `delete[]` |
| 02 | `brain` | Pointers vs. references, memory addresses |
| 03 | `weapon` | Aggregation via reference (`HumanA`) vs. pointer (`HumanB`) |
| 04 | `sed` | A tiny `sed`-like find & replace on a file |
| 05 | `harl2` | Function pointers on member functions, a complaint dispatcher |
| 06 | `harlFilter` | Same as above, but filtering by severity level |

### Module 02 — Ad-hoc polymorphism, operator overloading
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `fixed` | Fixed-point number class, raw bits only |
| 01 | `fixed` | Adds float/int constructors and `operator<<` |
| 02 | `fixed` | Full operator overloading (arithmetic, comparison, increment/decrement) |
| 03 | `fixed` | Binary Space Partitioning (`bsp`) — point-in-triangle test built on `Fixed` |

### Module 03 — Inheritance
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `claptrap` | Base `ClapTrap` class (attack/damage/repair) |
| 01 | `scavtrap` | `ScavTrap` inherits `ClapTrap`, adds `guardGuate()` |
| 02 | `fragtrap` | `FragTrap` inherits `ClapTrap`, adds `highFivesGuys()` |
| 03 | `diamondtrap` | Diamond (multiple/virtual) inheritance combining `ScavTrap` + `FragTrap` |

### Module 04 — Subtype polymorphism, abstract classes, interfaces
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `animal` | Virtual `makeSound()` vs. non-virtual (`WrongAnimal`/`WrongCat`) |
| 01 | `animal` | Adds a `Brain` member, deep vs. shallow copy |
| 02 | `animal` | `Animal` becomes a pure abstract class |
| 03 | `materia` | Interfaces (`ICharacter`, `IMateriaSource`), `AMateria::clone()` |

### Module 05 — Exceptions
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `bureaucrat` | `Bureaucrat` with grade bounds and custom exceptions |
| 01 | `form` | `Form` that can be signed, grade-checked exceptions |
| 02 | `form` | Abstract `AForm` + 3 concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) |
| 03 | `form` | Adds `Intern`, a factory that builds any of the 3 forms by name |

### Module 06 — C++ casts
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `scalar` | `ScalarConverter`: converts a literal to char/int/float/double |
| 01 | `serializer` | `reinterpret_cast` round-trip (pointer ↔ `uintptr_t`) |
| 02 | `identify` | `dynamic_cast` to identify the runtime type of `A`/`B`/`C` |

### Module 07 — Templates
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `whatever` | Generic `min`/`max`/`swap` function templates |
| 01 | `iter` | Generic `iter()` applying a function to every element of an array |
| 02 | `array` | Generic `Array<T>` container with bounds-checked `operator[]` |

### Module 08 — Templated containers, STL
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `easyfind` | Generic `easyfind()` using `std::find` over any container |
| 01 | `span` | `Span` class computing the longest/shortest span in a set of ints |
| 02 | `mutant` | `MutantStack<T>`: a `std::stack` with iterator support |

### Module 09 — STL, algorithms
| Ex | Binary | Topic |
|----|--------|-------|
| 00 | `btc` | Bitcoin exchange rate lookup from `data.csv`, given a date/value CSV |
| 01 | `RPN` | Reverse Polish Notation calculator |
| 02 | `PmergeMe` | Ford-Johnson (merge-insertion) sort implemented with both `std::vector` and `std::deque`, with timing comparison |

## Notes

- `Module9/ex00` ships with a reference `data.csv` (historical BTC/USD rates) and a sample `input.csv` to test against.
- Several exercises intentionally include a "Wrong" variant (`WrongAnimal`, `WrongCat`) to demonstrate what happens without `virtual`.
- Later modules progressively relax the Orthodox Canonical Form requirement where the exercise calls for it (e.g. templates, interfaces).
