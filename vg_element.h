
#ifndef vg_element_h
#define vg_element_h

#include <iostream>

class VG_element
{
public:
    VG_element()
    {}
    VG_element(std::string & context)
    {
        // parse context (coordinates, color)
        std::cout << __FUNCTION__ << ", context : " << context << std::endl;
    }
    virtual void draw() {}
    virtual void remove() {}
};

class Line : public VG_element
{

public:
    
    void draw() override
    {
    }
    void remove() override
    {
    }
};


#endif /* vg_element_h */
