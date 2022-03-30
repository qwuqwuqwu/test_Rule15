#include <iostream>
#include "Investment.h"
#include "InvestmentKeeper.h"

void ReleaseInvestmentDirectly( Investment *pInv ); // global function in main

InvestmentKeeper::InvestmentKeeper( Investment * pInv ):
m_pInv( pInv )
{
    std::cout << "InvestmentKeeper constructor" << std::endl;
    std::cout << "Keep investment address is " << m_pInv << std::endl;
}

InvestmentKeeper::~InvestmentKeeper()
{
    std::cout << "InvestmentKeeper destructor" << std::endl;
    std::cout << "Keep investment address is " << m_pInv << std::endl;
    ReleaseInvestmentDirectly( m_pInv );
}

Investment * InvestmentKeeper::get( void ) const
// my explicit casting function
{
    return m_pInv;
}

InvestmentKeeper::operator Investment*()
// implicit casting
{
    return m_pInv;
}