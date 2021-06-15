#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct DCEL {
    struct HalfEdge *edgeArray;
    struct Vertex   *vertexArray;
    struct Face     *faceArray;
}DCEL;

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
    HalfEdge *incidentEdge; //pointer to any one half-edge for which f is the incident face
    //Any attributes can be added here
}Face;

DCEL *makeDCEL(); //Creates an empty DCEL, it contains no vertices or edges, but contains a single outer(unbounded) face.
int getNumberOfFaces(DCEL *d); //Returns the number of faces in the DCEL.
int getNumberOfEdges(DCEL *d); //Returns the number of edges in the DCEL.
int getNumberOfVertices(DCEL *d); //Returns the number of vertices in the DCEL
HalfEdge *nextIncidentEdge(Vertex *v, HalfEdge *e); //Given an edge e, incident at a vertex v, this function returns the next incident edge in CCW order leaving the vertex v.
Vertex *destination(HalfEdge *e); //Returns the destination vertex of an edge e
Vertex *makeVertex(DCEL *d, double x, double y); //Creates and returns a new vertex at the given point location in DCEL d
 
int main( ) {
    

   return 0;
}

DCEL *makeDCEL(){
    Face *outerFace; DCEL *dcel;
    dcel->faceArray = malloc(sizeof(Face));
    dcel->faceArray[0] = *outerFace;
    return dcel;
}
int getNumberOfFaces(DCEL *d){
    return sizeof(d->faceArray) / sizeof(Face);
}
int getNumberOfEdges(DCEL *d){
    return sizeof(d->edgeArray) / sizeof(HalfEdge);
}
int getNumberOfVertices(DCEL *d){
    return sizeof(d->vertexArray) / sizeof(Vertex);
}
HalfEdge *nextIncidentEdge(Vertex *v, HalfEdge *e){
}

Vertex *destination(HalfEdge *e){
}
Vertex *makeVertex(DCEL *d, double x, double y){
    Vertex *newVertex;
    newVertex->xCoordinate = x;
    newVertex->yCoordinate = y;
    newVertex->incidentEdge = NULL;
    d->vertexArray = malloc(sizeof(Vertex));
    d->vertexArray[sizeof(d->vertexArray) / sizeof(Vertex)] = *newVertex;
    return newVertex;
}



