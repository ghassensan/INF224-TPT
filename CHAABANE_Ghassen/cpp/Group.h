#ifndef GROUP_H
#define GROUP_H

#include<list>
#include<memory>
#include<string>
#include"Multimedia.h"

/**
 * @brief The Group class
 */
class Group : public std::list<std::shared_ptr<Multimedia>>
{
private:
    // variable d'instance
    std::string name;

public:
    // Constructeur
    /**
     * @brief Group
     * @param _name
     */
    Group(std::string _name=""):name(_name){}

    //destructeur
    ~Group() {
        std::cout << "WHYYYYYYYYYY !! I M A GROUP!!!"<< std::endl;
    }

    // setters
    /**
     * @brief setName
     * @param _name
     */
    void setName(std::string _name){name=_name;}

    // getters
    /**
     * @brief getName
     * @return
     */
    std::string getName() const {return name;}

    //Fonction d'affichage
    /**
     * @brief print
     * @param out
     */
    void print(std::ostream& out = std::cout)
    {
        for(auto & it : *this)
        {
            it->print(out);
        }
    }
};

#endif // GROUP_H
