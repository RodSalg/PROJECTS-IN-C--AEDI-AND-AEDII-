typedef struct ponto Ponto;
struct ponto{
    float x;
    float y;
    float z;
};

Ponto *cria();
void acessa(Ponto *p, float *x, float *y, float *z);
void atribui(Ponto *p, float x, float y, float z);
float distancia(Ponto *p1, Ponto *p2);
void imprime(Ponto *ponto);

