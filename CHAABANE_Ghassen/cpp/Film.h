#ifndef FILM_H
#define FILM_H

#include"Video.h"
/**
 * @brief The Film class
 */
class Film : public Video
{
private:
    unsigned int nbrChap = 0;
    int *chap = nullptr;
public:
    // Constructeur
    /**
     * @brief Film
     * @param _name
     * @param _path
     * @param _duration
     * @param _chap
     * @param _nbrChap
     */
    Film(std::string _name="", std::string _path="", unsigned long long int _duration = 0ll,
         int * _chap = nullptr, unsigned int _nbrChap = 0):
        Video(_name, _path, _duration),nbrChap(_nbrChap)
    {
        chap = new int [nbrChap];
        for (unsigned int k = 0; k < nbrChap; k++)
        {
            chap[k]=_chap[k];
        }
    }

    //copy constructor
    /**
     * @brief Film
     * @param _film
     */
//    Film(const Film & _film):Video(_film)
//    {
//        nbrChap = _film.nbrChap;
//        if (nbrChap)
//        {
//            setChap(_film.nbrChap,_film.chap);
//        }
//    }

    // = copy with operator
    /**
     * @brief operator =
     * @param _film
     * @return
     */
//    Film& operator=(const Film& _film)
//    {
//        Video::operator=(_film);
//        nbrChap = _film.nbrChap;
//        delete [] chap;
//        chap = nullptr;
//        if(nbrChap)
//            setChap(_film.nbrChap,_film.chap);
//        return *this;
//    }

    // Destructeur
    ~Film() override
    {
        delete [] chap;
        chap = nullptr;
    }

    // setters
    /**
     * @brief setChap
     * @param _nbrChap
     * @param _chap
     */
    void setChap(unsigned int _nbrChap, const int * _chap)
    {
        nbrChap = _nbrChap;
        delete [] chap;
        chap = nullptr;
        if (nbrChap)
        {
            chap = new int[nbrChap];
        }
        for (unsigned int k = 0; k < nbrChap; k++)
        {
            chap[k]=_chap[k];
        }
    }
    // getters
    /**
     * @brief getNbrChap
     * @return
     */
    unsigned int getNbrChap() const {return nbrChap;}
    /**
     * @brief getChap
     * @return
     */
    const int* getChap() const {return chap;}
    /**
     * @brief getChapNbr
     * @param _nbr
     * @return
     */
    int getChapNbr(unsigned int _nbr) const
    {
        if (_nbr < nbrChap){
            return chap[_nbr];
        }
        else {
            std::cerr <<"OUT OF RANGE"<< std::endl;

        }
        return -1;
    }

    //Fonction d'affichage
    /**
     * @brief print
     * @param out
     */
    void print(std::ostream& out = std::cout) const override
    {
        Video::print(out);
        out << "Film's chapiter number is :  " << nbrChap << ";";
        for (unsigned int k = 0; k < nbrChap ; k++)
        {
            out << k+1 << " th Film chap duration is :  " << chap[k] << ";";
        }
        out << "=========================================================="<< ";";
    }
};

#endif // FILM_H
