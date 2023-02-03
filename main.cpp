#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    string question;
    Node *yes;
    Node *no;

    Node(string question) {
        this->question = question;
        yes = nullptr;
        no = nullptr;
    }
};

void ask(Node *node, Node *previous_node) {
    string answer;

    if (node == nullptr) {
        cout << "***********************************************" << endl
             << "You win... I don't know what you're thinking of" << endl
             << "***********************************************" << endl;

        cout << "What were you thinking of?" << endl;
        string animal;
        cin >> animal;

        cout << "What attribute would distinguish a " << animal
             << " from a the other animals?" << endl;
        string attribute;
        cin >> attribute;

        cout << "Adding " << animal << " to the tree." << endl;

        Node *question_node = new Node("Does it have " + attribute + "?");
        question_node->yes = new Node("Is it a " + animal + "?");

        previous_node->no = question_node;

        return;
    }

    previous_node = node;

    cout << node->question << " (y/n) ";
    cin >> answer;

    if (answer == "y") {
        if (node->yes == nullptr) {
            cout << "******\nI win!\n******" << endl;
        } else {
            ask(node->yes, node);
        }
    } else {
        ask(node->no, node);
    }
}

int main() {
    Node *root = new Node("Does it have 4 legs?");
    root->yes = new Node("Is it a dog?");
    root->no = new Node("Can it fly?");
    root->no->yes = new Node("Is it a penguin?");

    char play_again = 'y';

    while (true) {
        ask(root, nullptr);

        cout << "Would you like to play again? (y/n) ";
        cin >> play_again;

        if (play_again != 'y') {
            break;
        }
    }

    return 0;
}
