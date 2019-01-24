#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <iostream>
#include <map>

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual bool isAlive();
        virtual void takeDamage(int dgt);
        virtual void takeMagicDamage(int dgt);
        virtual void dealDamage(Entity &cible, int degats, int nbrAtk);
        virtual void dealDamage(Entity &cible, int degats, int nbrAtk, std::string type);
        virtual void resetBonusAtkDef();





        //virtual void isBleeding();
        //void attaqueBase(Entity &cible);

        virtual std::string getName();
        virtual void changeName(std::string newName);
        virtual int getLifeMax();
        virtual void modifLifeMax(int lifeMaxModif);
        virtual int getLifeActual();
        virtual void modifLifeActual(int lifeModif);
        virtual int getManaMax();
        virtual void modifManaMax(int manaMaxModif);
        virtual int getManaActual();
        virtual void modifManaActual(int manaModif);
        virtual int getResilience();
        virtual void modifResilience(int resiModif);
        virtual int getAtk();
        virtual void modifAtk(int atkModif);
        virtual int getDef();
        virtual void modifDef(int defModif);
        virtual int getBonusAtk();
        virtual void modifBonusAtk(int bonusAtkModif);
        virtual int getBonusDef();
        virtual void modifBonusDef(int bonusDefModif);

        // sans la map
        /*
        virtual int getStatus();
        virtual int getStatusCount();
        virtual void setStatus(int statusInflicted, int statusTime);
        virtual void clearStatus();
        */

        // avec la map !
        virtual void modifStatus(int statusTaken, int ctrStatusTaken);
        virtual void mapStatusCheck();
        virtual int isStunned();
        virtual void testDisplayStatusMap();
      //  virtual void allClearMapStatus();

      //  void setName(std::string newName);

    protected:
        std::string _EntityName;
        int _lifeMax;
        int _lifeActual;
        int _manaMax;
        int _manaActual;
        int _resilience;
        int _atk;
        int _def;
        int _bonusAtk;
        int _bonusDef;
        int _nbrAtk;    //plus utilisé ?

        /*
        Ancienne version, sans map
        int _status;
        int _ctrStatus;
        */
        // tests des status en map
        // nomStatus, ctrStatus
        std::map<std::string, int> _statusMap;


    private:

};

#endif // ENTITY_H
