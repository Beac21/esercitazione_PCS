#include <concepts>
#include <iostream> 
#include <numeric>


template<typename I> 
	requires std::integral<I> /*ci dice che la classe funziona solo con interi*/
class rational {
	I num_;
	I den_;
	void simplify() {
		if (den_ == 0) return;

        I g = std::gcd(num_,den_);
        num_ /= g;
        den_ /=g;

        if (den_<0)
        {
            num_=-num_;
            den_=-den_;
        }
    }     

public :
	/* Costruttore di default */
    rational()
        : num_(0), den_(1) 
    {}
	/* Costruttore user_defined*/
	rational (I n , I d)
		: num_(n), den_(d) 
		{ if (d!=0) simplify();
		}
	/*restituisce valori di x e y*/
	I num() const {return num_;}
	I den() const {return den_;}
	
	/*Implementazione della somma tra due numeri razionali*/
	rational operator+=(const rational& other) {
		num_= num_*other.den_ + other.num_*den_;
		den_= den_*other.den_;
		simplify();
		return *this;
	}
	/*Implementazione canonica, implementa += e restituisce risultato*/
	rational operator+(const rational& other)const
    {
        rational ret = *this;
        ret += other;
        return ret;
    }
	/*Implementazione della sottrazione tra due numeri razionali*/
	rational operator-=(const rational& other)
	 {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }
	/*Implementazione canonica, implementa -= e restituisce risultato*/
	rational operator-(const rational& other)const
    {
        rational ret = *this;
        ret -= other;
        return ret;
    }
	/*Implementazione del prodotto tra due numeri razionali*/
	rational operator*=(const rational& other)
	{
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }
	/*Implementazione canonica, implementa *= e restituisce risultato*/
	rational operator*(const rational& other)const 
    {
        rational ret = *this;
        ret *= other;
        return ret;
    }
	/*Implementazione della divisione tra due numeri razionali*/
	rational operator/=(const rational& other)
	{
        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }
	/*Implementazione canonica, implementa /= e restituisce risultato*/
	rational operator/(const rational& other)const 
    {
        rational ret = *this;
        ret /= other;
        return ret;
    } 

 };
 
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{   /*gestione casi Inf e NaN*/
    if (r.den() == 0)
    {
        if (r.num() == 0)
            os << "NaN";
        else
            os << "Inf";
    }
    else
    {
        os << r.num() << "/" << r.den();
    }
    return os;
};