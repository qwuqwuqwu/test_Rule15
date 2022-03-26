#include <iostream>
#include "Investment.h"
#include "InvestmentKeeper.h"

void ReleaseInvestmentDirectly( Investment *pInv ); // global function in main

InvestmentKeeper::InvestmentKeeper( Investment * pInv ):
m_pInv( pInv )
{
    std::cout << "InvestmentKeeper constructor" << std::endl;
}

InvestmentKeeper::~InvestmentKeeper()
{
    ReleaseInvestmentDirectly( m_pInv );
    std::cout << "InvestmentKeeper destructor" << std::endl;
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