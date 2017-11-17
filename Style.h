#ifndef STYLE_H
#define STYLE_H

#include "Carte.h"


class Style : public Carte
{
    public:
        Style(std::string name, std::string description);
        virtual ~Style();

        virtual int GetType(){return 3;}
        void Settype(int val) { m_type = val; }

    protected:

    private:
        int m_type;
};

#endif // STYLE_H
