#include <iostream>
#include "Investment.h"

Investment::Investment( const int& nDaysHeld ):
m_nDaysHeld( nDaysHeld )
{
    std::cout << "Investment constructor" << std::endl;
    std::cout << "Investment address is " << this << std::endl;
}

Investment::~Investment()
{
    std::cout << "Investment destructor" << std::endl;
    std::cout << "Investment address is " << this << std::endl;
}

const int& Investment::GetDaysHeld( void )
{
    return m_nDaysHeld;
}

bool Investment::IsTaxFree( void ) const
{
    return false;
}