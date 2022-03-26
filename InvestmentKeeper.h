#ifndef INVESTMENTKEEPER_H_
#define INVESTMENTKEEPER_H_

class InvestmentKeeper {
public:
    explicit InvestmentKeeper( Investment * pInv );
    ~InvestmentKeeper();

    Investment * get( void ) const;
    // explicit casting

    operator Investment*();
    // implicit casting

private:
    Investment *m_pInv;
};
#endif