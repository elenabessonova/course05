#ifndef vg_document_h
#define vg_document_h

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "vg_element.h"


class VG_document
{
public:
    
    void clear_document()
    {
        __elements.clear();
    }
    
    void make_new_doc(const std::string & filename)
    {
        std::cout << __FUNCTION__ << ", filename : " << filename << std::endl;
    }
    void import_doc(const std::string & filename)
    {
        std::cout << __FUNCTION__ << ", filename : " << filename << std::endl;
    }
    void export_doc(const std::string & filename)
    {
        std::cout << __FUNCTION__ << ", filename : " << filename << std::endl;
    }
    void add_vg_element(std::shared_ptr<VG_element> elem)
    {
        __elements.push_back(elem);
    }
    void remove_vg_element(std::shared_ptr<VG_element> elem)
    {
        auto it = __elements.begin();
        while(it != __elements.end())
        {
            if (*it == elem)
            {
                it = __elements.erase(it);
            }
            ++it;
        }
    }
private:
    std::vector<std::shared_ptr<VG_element>> __elements;

};

#endif /* vg_document_h */
