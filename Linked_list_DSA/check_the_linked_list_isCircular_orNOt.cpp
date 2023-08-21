bool isCircular(Node* head){
    // if the list has no node or the list is null -> then the list is circular;
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != head){
        temp = temp->next;
        if(temp == NULL){
            return false;
        }
    }

    return true;
}