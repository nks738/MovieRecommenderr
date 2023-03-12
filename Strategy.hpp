#ifndef _STRATEGY_HPP_
#define _STRATEGY_HPP_

class Factory;

class Strategy {
  public: 
    Strategy(){};
    virtual void filter(Factory* factory_pointer) = 0;
};
#endif

