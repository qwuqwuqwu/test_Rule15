#include <iostream>
#include "Investment.h"
#include "InvestmentKeeper.h"

Investment *g_pInvestment = NULL;

Investment * createInvestment()
// factory function
{
    if( g_pInvestment == NULL ) {
        g_pInvestment = new Investment( 10 );
    }
    return g_pInvestment;
}

void ReleaseInvestmentDirectly( Investment *pInv )
{
    delete g_pInvestment;
    g_pInvestment = NULL;
}

const int& GetDaysHeld( Investment *pInv )
{
    return pInv->GetDaysHeld();
}

void ExampleI( void )
{
    Investment *pLocalInv = createInvestment();
    std::shared_ptr< Investment > pSharedInv( createInvestment() );

    // example 1
    // argument is a pointer to Investment, not a shared pointer
    // GetDaysHeld( pSharedInv ); // GetDaysHeld( &pSharedInv ); // <---------Try to uncomment this line
    GetDaysHeld( pLocalInv );

    // example 1-1
    // resource managing class provide "get()" function
    // as a method to do explicit casting
    GetDaysHeld( pSharedInv.get() );

    // example 1-2
    // resource managing class overload "operator->", "operator*"
    // as a method to do implicit casting
    pSharedInv->IsTaxFree();
    ( *pSharedInv ).IsTaxFree();
}

void ExampleII( void )
{
    // example 2
    InvestmentKeeper MyInvestKeeper( createInvestment() );

    // example 2-1
    // write your get(), explicit casting
    std::cout << "Held day 2-1 = " << GetDaysHeld( MyInvestKeeper.get() ) << std::endl;

    // example 2-2
    // write your operator, implicit casting
    std::cout << "Held day 2-2 = " << GetDaysHeld( MyInvestKeeper ) << std::endl;

    // example 2-3
    // implicit casting may lead to some horror situation
    Investment *pLocalInv = MyInvestKeeper;
    //delete pLocalInv; // accidentally copy raw pointer and delete it roughly // <---------Try to uncomment this line
}

int main( void ) {
    
    // ExampleI();
    ExampleII();

    return 0;
}

