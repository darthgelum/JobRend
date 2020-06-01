#pragma once
#include <SDL_stdinc.h>
class Color
{
public:

    Color();


    Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);


    explicit Color(Uint32 color);

    Uint32 toInteger() const;


    static const Color Black;      
    static const Color White;      
    static const Color Red;         
    static const Color Green;       
    static const Color Blue;        
    static const Color Yellow;      
    static const Color Magenta;     
    static const Color Cyan;        
    static const Color Transparent; 

    
    
    
    Uint8 r; 
    Uint8 g; 
    Uint8 b; 
    Uint8 a; 

    
};

bool operator ==(const Color& left, const Color& right);
bool operator !=(const Color& left, const Color& right);
Color operator +(const Color& left, const Color& right);
Color operator -(const Color& left, const Color& right);
Color operator *(const Color& left, const Color& right);
Color& operator +=(Color& left, const Color& right);
Color& operator -=(Color& left, const Color& right);
Color& operator *=(Color& left, const Color& right);