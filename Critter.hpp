/******************************************************************************
** Author:      Winter 162 400 Group 4
** Date:        02/01/2019
** Description: This is a declaration of the Critter, Ant, and Doodlebug
**              classes.
******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP


class Critter
{
    protected:
        int x_pos;
        int y_pos;
        int age;
        char symbol;

    public:
        Critter();
        virtual ~Critter(){};
        virtual bool move(Critter ***);
        virtual void breed(Critter ***){};
    
        char getSymbol();
        int getX_pos();
        void setX_pos(int);
        int getY_pos();
        void setY_pos(int);
        void print_board(Critter ***);
};

/*class Ant : public Critter
{
	
};*/

class Doodlebug : public Critter
{
    private:
	int hunger;
    
    public:
        Doodlebug(int, int);
        ~Doodlebug(){};
        bool move(Critter ***);
        void breed(Critter *** &);
    
	
	
};

#endif
