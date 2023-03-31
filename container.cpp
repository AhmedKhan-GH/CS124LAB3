#include "container.h"

//refers to extern int in header
int ledger = 0;

Path::Path(){};

void Container::update_ledger(int update)
{
    /*
        +1 prepares ledger for next const initialization since next constructor iterates 
        ledger after initializing object id const
    */
    if (update >= ledger) 
    {
        ledger = update + 1;    
    }
}

//function that repeats a concatenated duplicate string or char
template<typename T>
std::string repeat(T repeat, int count)
{
    std::string temp = "";
    for(int i = 0; i < count; i ++)
    {
        temp += repeat;
    }
    return temp;
}

void Path::append(Container* node)
{
    nodes.push_back(node);
}

Path Container::get_path()
{
    Path path;
    //for looping from given node and iterating to root node
    for(Container* temp = this; temp != nullptr; temp = temp->parent) 
    {
        path.append(temp);
        //appending node to the beginning of the path list
    }
    return path;
}

void Path::print()
{
    //empty string creation
    std::string path; 
    //for looping from given node and iterating to root node
    for(auto const& it : nodes) 
    {
        //appending path elemeent to the beginning of the existing string
        path = char(179) + std::to_string(it->get_id()) + ":\"" + it->get_name() + "\"" + path; 
    }
    //adding root identifier
    path = "INV:" + path;
    //printing to console
    std::cout << std::endl << path << std::endl;
}

void Container::print_tree()
{
    _print_tree(0);
    std::cout << std::endl;
}

void Container::_print_tree(int depth)
{
    //prints a list element with the given depth
    std::cout << std::endl << repeat<char>(char(179), depth) << this->id << ":\"" << this->name << "\"";

    //checks if node is not a leaf
    if(!(this->children.empty()))
    {
        //given node is not leaf, loop iterates through child nodes calling _print_tree recursively
        for(auto it = this->children.begin(); it != this->children.end(); ++it)
        {
            //recursive function call with an increased depth, sincee the children are to be listed indented
            it->second->_print_tree(depth+1);
        }
    }
}

Container::~Container()
{
    //recursively iterates through all subnodes of a deletion target node calling its own destructor
    for(auto it = children.begin(); it != children.end(); ++it) 
    {
        delete it->second;
    }
}

Container::Container(std::string name) : id(ledger), name(name), parent(nullptr) 
{
    ledger++;
}

int Container::get_id() const
{
    return this->id; 
}

std::string Container::get_name() const
{
    return this->name; 
}

bool Container::nest(Container* node) 
{
    //REFERENCE: target: this, subject: node

    //node cannot nest inside itself
    if(node == this) 
    {
        std::cerr << std::endl << "ERROR: attempted to nest '" << name << "' within itself";
        return false;
    }

    /*
        if subject node is not a leaf, then further checks must be made to prevent insertion of subject
        into one of its own descdendants, and this is verified by taking the target node and following its
        ancestors up until either the subject is found (hence the target being a descendant of the
        subject) or nullptr is found, meaning a root node is found and the insertion is valid
    */

    /*
        initializing temp container as target node, setting break condition as reaching root node,
        and iterating by going one ancestor up the tree
    */
    for(Container* temp = this; temp != nullptr; temp = temp->parent) 
    {
        /*
            unless the subject node is found within the target node's ancestors, meaning target node
            is a descendant of the subject node, which is an invalid operation
        */
        if(temp == node) 
        {
            //breaks for loop on next iteration
            temp = nullptr; 
            //error message to console
            std::cerr << std::endl << "ERROR: attempted to nest '" << node->get_name() << "' within its descendant '" << name << "'";
            //exit from the function
            return false;
        }
    }

    /*
        if self nest and descendant conditions failsafes are passed, 
        subject node's parent is set to target
    */
    node->parent = this; 
    //and target node's map of children has subject node inserted
    children.emplace(node->id, node);
    //return of successful insertion indicator
    return true;
}