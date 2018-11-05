#ifndef VIDEO_H
#define VIDEO_H

#include"Multimedia.h"
/**
 * @brief The Video class
 */
class Video : public Multimedia
{
private:
    // variable d'instance
    unsigned long long int duration = 0ll;

public:
    // Constructeur
    /**
     * @brief Video
     * @param _name
     * @param _path
     * @param _duration
     */
    Video(std::string _name="", std::string _path="", unsigned long long int _duration = 0ll):
        Multimedia(_name,_path),duration(_duration){}

    // Destructeur
    ~Video() override{}

    // setters
    /**
     * @brief setDuration
     * @param _duration
     */
    void setDuration(unsigned long long int _duration){duration=_duration;}

    // getters
    /**
     * @brief getDuration
     * @return
     */
    unsigned long long int getDuration() const {return duration;}

    // Fonction d'affichage
    /**
     * @brief print
     * @param out
     */
    void print(std::ostream& out = std::cout) const override
    {
        Multimedia::print(out);
        out << "Video duration is :  " << duration << ";"
            << "=========================================================="<< ";";
    }

    // Fonction pour jouer l'objet
    /**
     * @brief play
     */
    void play()const override
    {
        std::string s;
        s="mpv "+path+name+" &";
        system(s.c_str());
    }
};
#endif // VIDEO_H
