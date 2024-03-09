#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/*
* Gonna make this easier on me
* and just explicitly declare all of the variables
*/

struct Input{
    //This is a bool that checks if there is any input at all
    //Just makes things slightly more efficent, no point in doing logic if this is false;
    bool input;
    //Movement
    bool w;
    bool a;
    bool s;
    bool d;
    //action
    bool e;
    //menu
    bool q;
    //quit
    bool esc;
    //special
    bool ctrl;
    //Restart with ctrl
    bool r;
    Input(){
        input = w = a = s = d = e = q = esc = ctrl = r = false; //This is set in the control function
    }
};

#endif // INPUT_H_INCLUDED
