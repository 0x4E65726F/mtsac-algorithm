#ifndef DFS_H
#define DFS_H

#include <map>
#include <string>

using namespace std;

template <typename G>
class DFS {						// generic DFS
protected: 						// local types
    typedef typename G::Vertex Vertex;			// vertex position
    typedef typename G::Edge Edge;			// edge position
    typedef typename G::Object Object;
    typedef typename G::VertexList VertexList;
    typedef typename G::EdgeList EdgeList;
    typedef typename G::VertexItor VertexItor;
    typedef typename G::EdgeItor EdgeItor;
protected: 						// member data
    const G& graph;					// the graph
    Vertex start;					// start vertex
    Object *yes, *no;					// decorator values
protected:						// member functions
    DFS(const G& g);					// constructor
    void initialize();					// initialize a new DFS
    void dfsTraversal(const Vertex& v);			// recursive DFS utility
                            // overridden functions
    virtual void startVisit(const Vertex& v) {}		// arrived at v
                                // discovery edge e
    virtual void traverseDiscovery(const Edge& e, const Vertex& from) {}
                                // back edge e
    virtual void traverseBack(const Edge& e, const Vertex& from) {}
    virtual void finishVisit(const Vertex& v) {}	// finished with v
    virtual bool isDone() const { return false; }	// finished?
protected: 						// marking utilities
    void visit(const Vertex& v)		  { v.set("visited", yes); }
    void visit(const Edge& e)		  { e.set("visited", yes); }
    void unvisit(const Vertex& v)	  { v.set("visited", no); }
    void unvisit(const Edge& e)		  { e.set("visited", no); }
    bool isVisited(const Vertex& v)	  { return v.get("visited") == yes; }
    bool isVisited(const Edge& e)	  { return e.get("visited") == yes; }
};

template <typename G>					// constructor
DFS<G>::DFS(const G& g)
: graph(g), yes(new Object), no(new Object) {}

template <typename G>					// initialize a new DFS
void DFS<G>::initialize() {
    VertexList verts = graph.vertices();
    for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv)
        unvisit(*pv);					// mark vertices unvisited
    EdgeList edges = graph.edges();
    for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
        unvisit(*pe);					// mark edges unvisited
}

template <typename G>					// recursive traversal
void DFS<G>::dfsTraversal(const Vertex& v) {
    startVisit(v);  visit(v);				// visit v and mark visited
    EdgeList incident = v.incidentEdges();
    EdgeItor pe = incident.begin(); 
    while (!isDone() && pe != incident.end()) {		// visit v's incident edges
        Edge e = *pe++;
        if (!isVisited(e)) {				// discovery edge?
        visit(e);					// mark it visited
        Vertex w = e.opposite(v);			// get opposing vertex
        if (!isVisited(w)) {				// unexplored?
            traverseDiscovery(e, v);			// let's discover it
            if (!isDone()) dfsTraversal(w);		// continue traversal
        }
        else traverseBack(e, v);			// process back edge
        }
    }
    if (!isDone()) finishVisit(v);			// finished with v
}

#endif