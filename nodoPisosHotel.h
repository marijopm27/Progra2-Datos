 class nodoPiso {
   public:
    nodoPiso(int NumPiso, string nombre, int habitacionesd)
    {
       Nombre = nombre;
       piso = NumPiso;
       habitaciones = habitacionesd;
       der = NULL;
       izq =NULL;
       FB =0;
       Habitaciones = NULL;

    }


        string Nombre;
        int piso;
        int habitaciones;
        int FB;
        nodoPiso *der;
        nodoPiso *izq;
        nodoHabitaciones* Habitaciones;
        

    };
typedef nodoPiso *pnodoPiso;
