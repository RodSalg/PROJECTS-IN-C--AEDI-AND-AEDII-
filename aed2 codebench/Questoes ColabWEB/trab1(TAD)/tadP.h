
typedef struct ponto Ponto;

Ponto* cria (float x, float y, float z);

void libera (Ponto* p);

void acessa (Ponto* p, float* x, float* y, float *z);

void atribui (Ponto* p, float x, float y, float z);

float distancia (Ponto* p1, Ponto* p2);