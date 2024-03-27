#ifndef MAIN_HPP
#define MAIN_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate();
void    identify( Base* p );
void    identify( Base& p );

#endif
