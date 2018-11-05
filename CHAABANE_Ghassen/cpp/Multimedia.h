#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include<string>
#include<iostream>

/**
 * @brief The Multimedia class
 */
class Multimedia
{
protected:
    // variable d'instance
    std::string name = "",path = "";

public:
    // Constructeur
    /**
     * @brief Multimedia
     * @param _name
     * @param _path
     */
    Multimedia(std::string _name="", std::string _path="");

    // Destructeur
    virtual ~Multimedia();

    // Setters
    /**
     * @brief setName
     * @param _name
     */
    void setName(std::string _name);
    /**
     * @brief setPath
     * @param _path
     */
    void setPath(std::string _path);

    // Getters
    /**
     * @brief getName
     * @return
     */
    std::string getName() const;
    /**
     * @brief getPath
     * @return
     */
    std::string getPath() const;

    // Fonction d'affichage
    /**
     * @brief print
     * @param out
     */
    virtual void print(std::ostream& out = std::cout)  const;

    // Fonction pour jouer l'objet multimédia
    /**
     * @brief play
     */
    virtual void play()const =0;
};

#endif // MULTIMEDIA_H
