#ifndef BASE_CAL_HPP
#define BASE_CAL_HPP


#ifdef CRTP

template <typename T>
class base_cal
{
public:
    inline
    int do_cal(int & _val)
    {
        T& underlying = static_cast<T&>(*this);
        
        // std::cout<<"in base func"<<std::endl;
        
        return underlying.do_cal(_val);
    }
};

#else

class base_cal
{
public:
    virtual
    int do_cal(int& _val){return 0;}
};

#endif
#endif