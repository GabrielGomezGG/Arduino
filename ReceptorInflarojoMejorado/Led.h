

class Led
{
private:
    float subir, encenderApagar, bajar;   //codigos de los botones en decimal 
    bool isEncendido;   //verifica si el led esta encendido o apagado
    int numeroDePin;    //numero de pin de arduino 
    int brillo;     //de 0 a 255
    String color;

public:

    //pin, boton subir , boton encendido de led  , boton bajar , color
    Led(int _numeroDePin, float _bajar, float _encenderApagar, float _subir,  String _color){
        numeroDePin = _numeroDePin;
        subir = _subir;
        encenderApagar = _encenderApagar;
        bajar = _bajar;
        isEncendido = false;
        brillo = 0; 
        color = _color;
    } 

    //encender o apagar el led
    //apaga (0) o enciende el led (255)
    void offOn(){
        if(!isEncendido){
            isEncendido = true;
            brillo = 255;
            analogWrite(numeroDePin, brillo);
        }
        else{
            isEncendido = false;
            brillo = 0;
            analogWrite(numeroDePin, brillo);
        }
    }


    //sube el brillo +15
    void subirBrillo(){
        if(isEncendido){
            if(brillo >= 0 && brillo < 255){
                brillo+=15;
                analogWrite(numeroDePin, brillo);
            }
        }
    }

    //baja el brillo -15
    void bajarBrillo(){
        if(isEncendido){
            if(brillo > 0 && brillo <= 255){
                brillo-=15;
                analogWrite(numeroDePin, brillo);
            }
        }
    }

    //getter

    String getColor(){
        return color;
    }

    int getNumeroDePin(){
        return numeroDePin;
    }

    float getSubir(){
        return subir;
    }

    float getBajar(){
        return bajar;
    }

    float getEncenderApagar(){
        return encenderApagar;
    }

    //cambia el pin actual por el ingresado por parametro.
    void setPin(int newPin){
        numeroDePin = newPin;
    }
};