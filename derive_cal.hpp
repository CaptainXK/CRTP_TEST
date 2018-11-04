#ifndef DERIVE_CAL_HPP
#define DERIVE_CAL_HPP
#include <base_cal.hpp>
#include <iostream>

#ifdef CRTP

class derive_cal:public base_cal<derive_cal>
{
    public:
        derive_cal(){
            std::cout<<"crtp class"<<std::endl;
        }

        inline
        int do_cal(int& _val)
        {
            // std::cout<<"in derive func"<<std::endl;
            return ++_val;
        }
};

#else

class derive_cal:public base_cal 
{
    public:
        derive_cal(){
            std::cout<<"normal derive class"<<std::endl;
        }

        virtual
        inline//inline virtual func, that will be ignored by compiler 
        int do_cal(int& _val)
        {
            return ++_val;
        }
};

#endif

#endif