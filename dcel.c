#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct DCEL {
    struct HalfEdge *edgeArray;
    struct Vertex   *vertexArray;
    struct Face     *faceArray;
}DCEL;

typedef struct Vertex {
    double *xCoordinate;
    double *yCoordinate;
    struct HalfEdge *incidentEdge; //pointer to any one incident edge originating from this vertex
    //Any attributes can be added here
}Vertex;

typedef struct HalfEdge {
    Vertex *originVertex; //half-edge originates from this vertex
    struct HalfEdge *twinEdge; //pointer to its twin
    struct Face *incidentFace; //left face edge is incident on
    struct HalfEdge *nextEdge; //half-edge around the incident (left) face.
    struct HalfEdge *prevEdge; // previous half-edge around the incident (left) face.
    //Any attributes can be added here
}HalfEdge;

typedef struct Face {
    HalfEdge *incidentEdge; //pointer to any one half-edge for which f is the incident face
    //Any attributes can be added here
}Face;

DCEL *makeDCEL(); //Creates an empty DCEL, it contains no vertices or edges, but contains a single outer(unbounded) face.
 
int main( ) {
    
   return 0;
}


DCEL *makeDCEL(){
    Face *outerFace; DCEL *dcel;
    dcel->faceArray = malloc(sizeof(Face));
    dcel->faceArray[0] = *outerFace;
    return dcel;
}
