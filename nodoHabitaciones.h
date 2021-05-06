class nodoHabitaciones{
    public:
    nodoHabitaciones(int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado,nodoHabitaciones *l,nodoHabitaciones *r,char col)
    {

       codHabitacion = codigoHabitacion;
       cuarto = cuartos;
       camas = Numcamas;
       precio = Precio;
       estado = Estado;
       der = r;
       izq =l;
       color = col;
       
    }
    
    
    int piso;
    int codHabitacion;
    string cuarto;
    int camas;
    int precio;
    string estado;
    int codigo;
    char color;
    nodoHabitaciones *padre;
    nodoHabitaciones *der;
    nodoHabitaciones *izq;

};
typedef nodoHabitaciones *pnodoHabitaciones;
