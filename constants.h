#ifndef TABLES_H
#define TABLES_H

const char tabencryptxy[62] = {'X', 'u', 'P', '4', 'N', 'G', 'Z', '8', 'n', 'g', 'I', 'c', 'j', 'K', 'M',
                               '7', 'W', 'Q', 'T', 'b', '2', 'q', 'C', '1', 'e', 'h', 'O', 'o', 't', 'L',
                               'H', '9', 'z', 's', 'm', 'a', 'w', 'J', 'S', 'Y', 'l', 'A', 'i', 'f', 'U',
                               'v', 'y', 'r', 'k', 'E', 'D', 'x', '3', '6', '5', 'F', 'p', '0', 'V', 'R',
                               'd', 'B'};

const char tabencryptnbr62x[25] = {'x', 'G', '3', 'r', '8', 'k', 'T', 'Q', 'm', 'Y', 'I', 'c', 'j', 'K', 'M',
                                   '7', 'W', 'b', '2', 'q', 't', 'L', 'H', '9', 'f'};

const char tabencryptsignes[4] = {'2', 'A', '9', 'r'};

const double xRatios[24] = {0.160000007599592 , 8.00000037997961e-002 , 4.00000018998981e-002 , 2.0000000949949e-002 ,
                      1.00000004749745e-002 , 5.00000023748726e-003 , 2.50000011874363e-003 , 1.25000005937181e-003 ,
                      6.25000029685907e-004 , 3.12500014842954e-004 , 1.56250007421477e-004 , 7.81250037107384e-005 ,
                      3.90625018553692e-005 , 1.95312509276846e-005 , 9.7656254638423e-006  , 4.88281273192115e-006 ,
                      4.08833329856861e-006 , 2.04416679139285e-006 , 1.02208339569643e-006 , 5.11041697848214e-007 ,
                      2.55520848924107e-007 , 2.55519214675815e-007 , 2.55519214675815e-007 , 2.55519214675815e-007 };

const double yRatios[24] = {-0.160000007599592 , -8.00000037997961e-002 , -4.00000018998981e-002 , -2.0000000949949e-002 ,
                      -1.00000004749745e-002 , -5.00000023748726e-003 , -2.50000011874363e-003 , -1.25000005937181e-003 ,
                      -6.25000029685907e-004 , -3.12500014842954e-004 , -1.56250007421477e-004 , -7.81250037107384e-005 ,
                      -3.90625018553692e-005 , -1.95312509276846e-005 , -9.7656254638423e-006  , -4.88281273192115e-006 ,
                     -4.08833329856861e-006 , -2.04416679139285e-006 , -1.02208339569643e-006 , -5.11041697848214e-007 ,
                      -2.55520848924107e-007 , -2.55519214675815e-007 , -2.55519214675815e-007 , -2.55519214675815e-007 };
const int factRatio = 100;

const int tileSize=256;

const double pi  = 3.141592653589793238462;
const double r   = 637813700;               //rayon de la Terre en cm
const double phi0= 0.8115781021773631;

typedef enum {
    CARTE_IGN=0,
    PHOTOS,
    CADASTRE,
    CASSINI,
    TEST,
    } Couche;


#endif // TABLES_H
