#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Vertex {
    double xCoordinate;
    double yCoordinate;
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
    HalfEdge incidentEdge; //pointer to any one half-edge for which f is the incident face
    //Any attributes can be added here
}Face;

typedef struct DCEL {
    struct HalfEdge *edgeArray[100];
    struct Vertex  *vertexArray[100];
    struct Face    *faceArray[100];
    struct Face    *outerFace;
    int numberOfEdges;
    int numberOfVertices;
    int numberOfFaces;
}DCEL;

DCEL *makeDCEL(); //Creates an empty DCEL, it contains no vertices or edges, but contains a single outer(unbounded) face.
int getNumberOfFaces(DCEL *d); //Returns the number of faces in the DCEL.
int getNumberOfEdges(DCEL *d); //Returns the number of edges in the DCEL.
int getNumberOfVertices(DCEL *d); //Returns the number of vertices in the DCEL
HalfEdge *nextIncidentEdge(Vertex *v, HalfEdge *e); //Given an edge e, incident at a vertex v, this function returns the next incident edge in CCW order leaving the vertex v.
Vertex *destination(HalfEdge *e); //Returns the destination vertex of an edge e
Vertex *makeVertex(DCEL *d, double x, double y); //Creates and returns a new vertex at the given point location in DCEL d
Face *nextFace(Vertex *v, Face *f);//Given a face f that is adjacent to a vertex v, returns the next face in CCW order that is adjacentto a vertex v
int numberOfFaces(Vertex *v); //Returns the number of faces adjacent to a vertex v
Face *getCommonFace(Vertex *v1, Vertex *v2); //Returns a common face between two vertices v1 and v2.
int isAdjacent(Vertex *v1, Vertex *v2); //Returns true (1) if and only if the two given vertices have a common edge between them.
HalfEdge *getIncidentEdge(Vertex *v, Face *f); //If exists, returns the HalfEdge that has v as its origin vertex and f as its incident face
Face *getOuterFace(DCEL *d); //Returns the single outer face in DCEL d.
int numberOfEdges(Face *f); //Returns the number of edges on the boundary of a face f.
HalfEdge *makeEdge(DCEL *d, Face *f, Vertex *v1, Vertex *v2); //Connects the two vertices v1 and v2 that belong to the same face (f) without splitting that face.
HalfEdge *splitFace(DCEL *d, Face *f, Vertex *v1, Vertex *v2); //Creates a new half edge between the vertices v1 and v2 which splits the face f into two new faces
 
int main() {
    
    DCEL *d = makeDCEL();
    Vertex *v1 = makeVertex(d, 0,0);
    Vertex *v2 = makeVertex(d, 1,0);
    Vertex *v3 = makeVertex(d, 1,1);
    Vertex *v4 = makeVertex(d, 0,9);

   return 0;
}

DCEL *makeDCEL(){
    DCEL *dcel = malloc(sizeof(DCEL));
    Face *outerFace = malloc(sizeof(Face));
    dcel->outerFace = outerFace;
    dcel->faceArray[0] = outerFace;
    dcel->numberOfEdges = 0;
    dcel->numberOfVertices = 0;
    dcel->numberOfFaces = 1;
    return dcel;
}
int getNumberOfFaces(DCEL *d){
    return d->numberOfFaces;
}
int getNumberOfEdges(DCEL *d){
    return d->numberOfEdges;
}
int getNumberOfVertices(DCEL *d){
    return d->numberOfVertices;
}
HalfEdge *nextIncidentEdge(Vertex *v, HalfEdge *e){
    return NULL;
}
Vertex *destination(HalfEdge *e){
    //e's twinEdge is same to e but has opposite direction
    return e->twinEdge->originVertex;
}
Vertex *makeVertex(DCEL *d, double x, double y){
    Vertex *newVertex=malloc(sizeof(Vertex));;
    newVertex->xCoordinate = x;
    newVertex->yCoordinate = y;
    newVertex->incidentEdge = NULL;
    d->vertexArray[d->numberOfVertices] = newVertex;
    d->numberOfVertices = d->numberOfVertices+1;
    return NULL;
}
Face *nextFace(Vertex *v, Face *f){
    return NULL;
}
int numberOfFaces(Vertex *v){
    return -1;
}
Face *getCommonFace(Vertex *v1, Vertex *v2){
    return NULL;
}
int isAdjacent(Vertex *v1, Vertex *v2){
    return -1;
}
HalfEdge *getIncidentEdge(Vertex *v, Face *f){
    return NULL;
}
Face *getOuterFace(DCEL *d){
    return d->outerFace;
}
int numberOfEdges(Face *f){
    return -1;
}
HalfEdge *makeEdge(DCEL *d, Face *f, Vertex *v1, Vertex *v2){
    return NULL;
}
HalfEdge *splitFace(DCEL *d, Face *f, Vertex *v1, Vertex *v2){
    return NULL;
}



