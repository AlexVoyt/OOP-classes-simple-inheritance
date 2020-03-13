#include <iostream>
#include <string>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

using namespace std;

enum Gender
{
    UNDEFINED,
    MALE,
    FEMALE
};

enum Degree
{
    BACHELOR,
    MAGISTER,
    PROFESSOR
};

enum Research
{
    MATH,
    PHYSICS,
    CHEMISTRY,
    ECOMOMICS
};

enum Skills
{
    FISH = 0x1,
    MEAT = 0x2,
    DESSERT = 0x4,
    VEGETABLES = 0x8
};


class Human
{
    u32 age;
    string fio;
    Gender gender;

    public:

    u32 Get_Age()
    {
        return age;
    }

    void Set_Age(u32 _age)
    {
        if(age < 0)
        {
            age = 0;
            // TODO
            // throw error;
        }
        else
        {
            age = _age;
        }

        return;
    }

    string Get_Fio()
    {
        return fio;
    }

    void Set_Fio(string _fio)
    {
        fio = _fio;
        return;
    }

    Gender Get_Gender()
    {
        return gender;
    }

    void Set_Gender(Gender _gender)
    {
        gender = _gender;
        return;
    }

    Human(u32 _age, string _fio, Gender _gender)
    {
        Set_Age(_age);
        Set_Fio(_fio);
        Set_Gender(_gender);
    }

};

class BloodDonor : public Human
{
    u32 amount_of_blood;

    public:

    u32 Get_Amount_Of_Blood()
    {
        return amount_of_blood;
    }

    void Set_Amount_Of_Blood(u32 _amount_of_blood)
    {
        if(_amount_of_blood < 0 || _amount_of_blood > 1000)
        {
            amount_of_blood = 0;
            // TODO
            // throw error;
        }
        else
        {
            amount_of_blood = _amount_of_blood;
        }

        return;
    }

    BloodDonor(u32 _age, string _fio, Gender _gender, u32 _amount_of_blood) :
         Human(_age, _fio, _gender)
    {
        Set_Amount_Of_Blood(_amount_of_blood);
    }

    u32 DonateBlood(u32 value)
    {
        u32 result = 0;
        s32 difference = Get_Amount_Of_Blood() - value;
        if(difference >= 0)
        {
            Set_Amount_Of_Blood(difference);
            result = value;
        }
        else
        {
            //TODO: throw exception error?
        }

        return result;
    }

};

class Scientist : public Human
{
    Degree degree;
    Research research;

    public:

    Degree Get_Degree()
    {
        return degree;
    }

    void Set_Degree(Degree _degree)
    {
        degree = _degree;
        return;
    }

    Research Get_Research()
    {
        return research;
    }

    void Set_Research(Research _research)
    {
        research = _research;
        return;
    }

    Scientist(u32 _age, string _fio, Gender _gender, Degree _degree, Research _research) :
         Human(_age, _fio, _gender)
    {
        Set_Degree(_degree);
        Set_Research(_research);
    }

    void DoResearch()
    {
        //TODO: do something interesting
        return;
    }
};

typedef uint8_t SkillSet;

class Cook : public Human
{
    SkillSet skill_set;

    public:

    SkillSet Get_Skill_Set()
    {
        return skill_set;
    }

    void Display_Skill_Set()
    {
        //TODO : display skillset somehow
    }

    void Set_Skill_Set(SkillSet _skill_set)
    {
        skill_set = _skill_set;
    }

    Cook(u32 _age, string _fio, Gender _gender, SkillSet _skill_set) :
         Human(_age, _fio, _gender)
    {
        Set_Skill_Set(_skill_set);
    }

};

class BloodDonorCook : public BloodDonor, public Cook
{
    public:
    BloodDonorCook(u32 _age, string _fio, Gender _gender, SkillSet _skill_set, u32 _amount_of_blood) :
        BloodDonor(_age, _fio, _gender, _amount_of_blood),
              Cook(_age, _fio, _gender, _skill_set) {}
};

int main(int argc, char *argv[])
{
    Human human_oleg(20, "oleg", MALE);
    cout << "HUMAN OBJECT"<< endl;
    cout << human_oleg.Get_Fio() << endl;
    cout << human_oleg.Get_Age() << endl;
    cout << human_oleg.Get_Gender() << endl;

    BloodDonor blood_donor_olya(23, "olya", FEMALE, 800);
    cout << "BLOOD DONOR OBJECT"<< endl;
    cout << blood_donor_olya.Get_Amount_Of_Blood() << endl;
    cout << blood_donor_olya.DonateBlood(500) << endl;
    cout << blood_donor_olya.Get_Amount_Of_Blood() << endl;

    Scientist scientist_dasha(32, "dasha", FEMALE, PROFESSOR, MATH);
    cout << "SCIENTIST OBJECT"<< endl;
    cout << scientist_dasha.Get_Degree() << endl;
    cout << scientist_dasha.Get_Research() << endl;

    Cook cook_sanya(28, "sanya", MALE, FISH|MEAT|VEGETABLES);
    cout << "COOK OBJECT"<< endl;
    int t = cook_sanya.Get_Skill_Set();
    cout << cook_sanya.Get_Skill_Set() << endl; //IMPORTANT: what the
    cout << t << endl;

    BloodDonorCook blood_donor_cook_misha(28, "misha", MALE, FISH|MEAT|VEGETABLES, 600);
    cout << "BLOOD DONOR COOK OBJECT"<< endl;
    cout << blood_donor_cook_misha.Get_Skill_Set() << endl; //still IMPORTANT: what the
    cout << blood_donor_cook_misha.Get_Amount_Of_Blood() << endl;

    return 0;
}
