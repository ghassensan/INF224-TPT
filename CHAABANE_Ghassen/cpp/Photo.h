#ifndef PHOTO_H
#define PHOTO_H

#include"Multimedia.h"
/**
 * @brief The Photo class
 */
class Photo : public Multimedia
{
private:
    // variable d'instance
    float latitude = 0.0f, longitude =0.0f;

public:
    // Constructeur
    /**
     * @brief Photo
     * @param _name
     * @param _path
     * @param _latitude
     * @param _longitude
     */
    Photo(std::string _name="", std::string _path="", float _latitude = 0.0f, float _longitude = 0.0f):
        Multimedia(_name,_path),latitude (_latitude), longitude (_longitude){}

    //destructeur
    ~Photo() override{}

    // setters
    /**
     * @brief setLatitude
     * @param _latitude
     */
    void setLatitude(float _latitude){latitude=_latitude;}
    /**
     * @brief setLongitude
     * @param _longitude
     */
    void setLongitude(float _longitude){longitude=_longitude;}

    // getters
    /**
     * @brief getLatitude
     * @return
     */
    float getLatitude() const {return latitude;}
    /**
     * @brief getLongitude
     * @return
     */
    float getLongitude() const {return longitude;}

    //Fonction d'affichage
    /**
     * @brief print
     * @param out
     */
    void print(std::ostream& out = std::cout) const override
    {
        Multimedia::print(out);
        out << "Photo latitude is :  " << latitude << ";"
            << "Photo longitude is :  " << longitude << ";"
            << "=========================================================="<< ";";
    }

    //Fonction pour jouer l'objet
    /**
     * @brief play
     */
    void play()const override
    {
        std::string s;
        s="display "+path+name+" &";    //on peut également utiliser imagej
        system(s.c_str());
    }
};
#endif // PHOTO_H
