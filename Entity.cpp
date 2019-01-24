#include "Entity.h"

Entity::Entity()
{
    //ctor
    _statusMap["stun"] = 0;
    _statusMap["bleed"] = 0;
    _statusMap["poison"] = 0;

    // test
    _statusMap["Shredded armor"] = 0;
    _statusMap["ShreddedCtr"] = 0;
}

Entity::~Entity()
{
    //dtor
}

//test modif de la map.
void Entity::modifStatus(int statusTaken, int ctrStatusTaken){
    if(statusTaken == 1){
        _statusMap["stun"] = ctrStatusTaken;
        std::cout << _EntityName << " is stunned." << "for " << ctrStatusTaken << " turns." << std::endl;
    }else if(statusTaken == 2){
        _statusMap["bleed"] = ctrStatusTaken;
        std::cout << _EntityName << " bleeds." << "for " << ctrStatusTaken << " turns." << std::endl;
    }else if(statusTaken == 3){
        _statusMap["poison"] = ctrStatusTaken;
        std::cout << _EntityName << " is poisoned." << "for " << ctrStatusTaken << " turns." <<std::endl;
    }else if(statusTaken == 4){
        _statusMap["Shredded armor"] = _def;
        _def = 0;
        _statusMap["ShreddedCtr"] = ctrStatusTaken;
        std::cout << _EntityName << "'s armor is shredded and no longer protect " << _EntityName << "for " << ctrStatusTaken << " turns." << std::endl;
    }
}

void Entity::mapStatusCheck(){
    if(_statusMap["bleed"] > 0){
        if(_lifeActual > 0){
            _lifeActual -= 1;
        }else if(_resilience > 0){
            _resilience -= 0;
        }
        _statusMap["bleed"]--;
        std::cout << _EntityName << " is bleeding and loses 1hp." << std::endl;
    }
    if(_statusMap["poison"] > 0){
        if(_lifeActual > 1){
            _lifeActual -= 2;
        }else if(_resilience > 0){
            _resilience -= 0;
        }
        _statusMap["poison"]--;
        std::cout << _EntityName << " is poisoned and loses 2hp." << std::endl;
    }
    if(_statusMap["stun"]> 0){
        _statusMap["stun"]--;
    }

    if(_statusMap["ShreddedCtr"] == 1){
        _def = _statusMap["Shredded Armor"];
        _statusMap["Shredded Armor"] = 0;
        _statusMap["ShreddedCtr"] = 0;
    }else{
        _statusMap["ShreddedCtr"]--;
    }
}

int Entity::isStunned(){
    return _statusMap["stun"];
}

void Entity::testDisplayStatusMap(){
    std::cout << _EntityName << " - Stun / Bleed / Poison : " << _statusMap["stun"] << "/" << _statusMap["bleed"] << "/" << _statusMap["poison"] << std::endl;
    std::cout << _EntityName << "isStun: " << isStunned() << std::endl;
}


void Entity::takeDamage(int dgt){
    int damageTaken = dgt-(_def+_bonusDef);
    if(damageTaken > 0){
        if(_lifeActual > damageTaken){
            _lifeActual -= damageTaken;
        }else if(_lifeActual > 0 && _lifeActual <= damageTaken){
            _resilience -= (damageTaken-_lifeActual);
            _lifeActual = 0;
        }else if(_lifeActual == 0){
            _resilience -= damageTaken;
        }
    }

    if(_lifeActual == 0 && _resilience <=0){
        // si jamais l'ennemi attaque plusieurs fois et que la cible meurt avant la dernière atk.
        std::cout << _EntityName << " died." << std::endl;
        _lifeActual = -1;
    }

}

void Entity::takeMagicDamage(int dgt){
    if(dgt > 0){
        if(_lifeActual > dgt){
            _lifeActual -= dgt;
        }else if(_lifeActual > 0 && _lifeActual <= dgt){
            _resilience -= (dgt-_lifeActual);
            _lifeActual = 0;
        }else if(_lifeActual == 0){
            _resilience -= dgt;
        }
    }

    if(_lifeActual == 0 && _resilience <=0){
        // si jamais l'ennemi attaque plusieurs fois et que la cible meurt avant la dernière atk.
        std::cout << _EntityName << " died." << std::endl;
        _lifeActual = -1;
    }

}


void Entity::dealDamage(Entity &target, int degats, int nbrAtk){
    int damageDealt = degats+_bonusAtk;
    int defTarget = target.getDef()+target.getBonusDef();
    if(defTarget < 0){
        defTarget = 0;
    }
    for(int i = 0; i < nbrAtk; i++){
        std::cout << _EntityName << " attacks and deals " << damageDealt-defTarget << " (" << defTarget
                << " blocked) to ";
        if(!target.isAlive()){std::cout << "dead ";}
        std::cout << target.getName() << "." << std::endl;
        target.takeDamage(damageDealt);
    }
}

void Entity::dealDamage(Entity &target, int degats, int nbrAtk, std::string type){
    if(type == "physical"){
        int damageDealt = degats+_bonusAtk;
        int defTarget = target.getDef()+target.getBonusDef();
        if(defTarget < 0){
            defTarget = 0;
        }
        for(int i = 0; i < nbrAtk; i++){
            std::cout << _EntityName << " attacks and deals " << damageDealt-defTarget << " (" << defTarget
                << " blocked) to ";
            if(!target.isAlive()){std::cout << "dead ";}
            std::cout << target.getName() << "." << std::endl;
            target.takeDamage(damageDealt);
        }
    }else if(type == "magical"){
        std::cout << _EntityName << " cast and deals " << degats << " magical damages to " << target.getName() << "." << std::endl;
        target.takeMagicDamage(degats);
    }
}

bool Entity::isAlive(){
    if(_lifeActual <=0 && _resilience <=0){
      //  std::cout << _EntityName << " is dead." << std::endl;
        return false;
    }else{
        return true;
    }
}

/*
void Entity::clearStatus(){
   // std::cout << "TEST. ENTERS CLEAR STATUS FOR _" << _EntityName << "_, ";
    if(_ctrStatus == 0){
        _status = 0;
     //   std::cout << "ctrStatus was equal 0 so status is equal 0. ctr / st : " << _ctrStatus << "/" <<_status << "..";
    }else{
        _ctrStatus--;
      //  std::cout << "ctrStatus was not equal 0 so was --. ctr / st : " << _ctrStatus << "/" <<_status << "..";
    }
    // std::cout << "end test" << std::endl;
}
*/
void Entity::resetBonusAtkDef(){
    _bonusAtk = 0;
    _bonusDef =0;
}
/*
void Entity::isBleeding(){
    if(_status == 2){
        if(_lifeActual >= 2){
            _lifeActual -= 2;
        }else if(_lifeActual < 2 && _resilience >= 0){
            _resilience = (_lifeActual - 2);
            _lifeActual = 0;
        }
        std::cout << _EntityName << " is bleeding and loses 2hp." << std::endl;
    }else if(_status == 3){
        if(_lifeActual >= 1){
            _lifeActual -= 1;
        }else if(_lifeActual < 1 && _resilience > 0){
            _resilience = (_lifeActual - 1);
            _lifeActual = 0;
        }
        std::cout << _EntityName << " is poisoned and loses 1hp." << std::endl;
    }
}*/

std::string Entity::getName(){
    return _EntityName;
}

int Entity::getLifeMax(){
    return _lifeMax;
}

void Entity::modifLifeMax(int lifeMaxModif){
    _lifeMax += lifeMaxModif;
}

int Entity::getLifeActual(){
    return _lifeActual;
}

void Entity::modifLifeActual(int lifeModif){
    _lifeActual += lifeModif;
    if(_lifeActual > _lifeMax){
        _lifeActual = _lifeMax;
    }else if(_lifeActual < 0){
        _lifeActual = 0;
    }
}

int Entity::getManaMax(){
    return _manaMax;
}

void Entity::modifManaMax(int manaMaxModif){
    _manaMax += manaMaxModif;

}

int Entity::getManaActual(){
    return _manaActual;
}

void Entity::modifManaActual(int manaModif){
    _manaActual += manaModif;
    if(_manaActual > _manaMax){
        _manaActual = _manaMax;
    }else if(_manaActual < 0){
        _manaActual = 0;
    }
}

int Entity::getResilience(){
    return _resilience;
}

void Entity::modifResilience(int resiModif){
    _resilience += resiModif;
    if(_resilience < 0){
        _resilience = 0;
    }
}

int Entity::getAtk(){
    return _atk;
}

void Entity::modifAtk(int atkModif){
    _atk += atkModif;
    if(_atk < 0){
        _atk = 0;
    }
}

int Entity::getDef(){
    return _def;
}

void Entity::modifDef(int defModif){
    _def += defModif;
    if(_def < 0){
        _def = 0;
    }
}

int Entity::getBonusAtk(){
    return _bonusAtk;
}

void Entity::modifBonusAtk(int bonusAtkModif){
    _bonusAtk += bonusAtkModif;
    if(_bonusAtk < 0){
        _bonusAtk = 0;
    }
}

int Entity::getBonusDef(){
    return _bonusDef;
}

void Entity::modifBonusDef(int bonusDefModif){
    _bonusDef = bonusDefModif;
    if(_bonusDef < 0){
        _bonusDef = 0;
    }
}


void Entity::changeName(std::string newName){
    _EntityName = newName;
}

