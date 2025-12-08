#include "Sed.hpp"

Sed::Sed( std::string fn, std::string s1, std::string s2 ) {
    _filename = fn;
    _s1 = s1;
    _s2 = s2;
}

Sed::~Sed( void ) {
}

bool Sed::isExist( void ) {
    std::ifstream is( _filename, std::ios::in );
    if (is.good()) {
        is.close();
        return true;
    }
    std::cout << "Error, file don't exist." << std::endl;
    is.close();
    return false;
}

void Sed::findAndReplace( void ) {
    // in -> Input mode.
    std::ifstream is( _filename, std::ios::in );
    std::string line;
    bool isStart = true;
    while (std::getline( is, line )) {
        if (!isStart) { writeNewLine("\n"); }
        isStart = false;
        std::string newLine = "";
	    size_t found = line.find( _s1 );
        size_t last_pos = 0;
        while ( found!=std::string::npos ) {
            newLine.append( line, last_pos, found - last_pos );
            newLine.append( _s2 );
            last_pos = found+_s1.length();
            found = line.find( _s1, found+_s1.length() );
        }
        newLine.append( line.substr(last_pos) );
        writeNewLine( newLine );
    }
}

void Sed::writeNewLine( std::string line ) {
    // app -> Append mode.
    // out -> Output mode.
    std::ofstream os( _filename+".replace", std::ios::out | std::ios::app );
    os.write( line.data(), line.length() );
}