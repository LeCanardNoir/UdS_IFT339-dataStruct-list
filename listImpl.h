//
//  listImpl.h
//
//  Auteur : Jean Goulet
//  Copyleft  2017 UdeS
//
//  Modifie par : Vincent Ducharme, Automne 2022
//
//  Devoir fait par
//     Co�quipier 1 : Bruno Pouliot
//     Co�quipier 2 : Gabriel Dumont-H�tu

#ifndef listImpl_h
#define listImpl_h

//////////////////////////////////////////////////////////////
//fonctions generatrices privees
//////////////////////////////////////////////////////////////

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::insert(cellule* c, const TYPE& VAL)
{
    //BUUUUUUUUUUUGGGGG
    cellule nouv;
    cellule* ptrNouv = &nouv;
    ptrNouv->m_contenu = VAL;
    prtNouv->m_prec = c->m_prec;
    c->m_prec = prtNouv;
    prtNouv->m_suiv = c;
    if (prtNouv->m_prec) {
        prtNouv->m_prec->m_suiv = prtNouv;
    }
    m_size++;
}

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::erase(cellule* c)
{
    if (size() > 0) {
        c->m_suiv->m_prec = c->m_prec;
        if(c->m_prec)
            c->m_prec->m_suiv = c->m_suiv;

        m_size--;
    }

    return c;
    
}


//////////////////////////////////////////////////////////////
//reverse_iterator
//////////////////////////////////////////////////////////////


template <typename TYPE>
class list<TYPE>::reverse_iterator
{
    friend class list<TYPE>;
    cellule* m_pointeur = nullptr;
    reverse_iterator() = default;
    reverse_iterator(cellule *c) :m_pointeur(c) {}
public:
    TYPE& operator*()const;
    TYPE* operator->()const;
    reverse_iterator& operator++(); //++i
    reverse_iterator operator++(int); //i++
    reverse_iterator& operator--(); //--i
    reverse_iterator operator--(int); // i--
    bool operator==(const reverse_iterator&droite)const;
    bool operator!=(const reverse_iterator&droite)const;
};

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rbegin()
{
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rend()
{
}

///////////////////////////////////////////////////////////
//affectateur
///////////////////////////////////////////////////////////

template <typename TYPE>
list<TYPE>& list<TYPE>::operator=(const list<TYPE>& droite)
{
    return *this;
}


///////////////////////////////////////////////////////////
//algorithme reverse
///////////////////////////////////////////////////////////

template <typename TYPE>
void list<TYPE>::reverse()
{
    if (m_debut) {
        std::swap(m_debut->m_prec, m_apres.m_prec->m_suiv);
        cellule* c = m_debut;
        while (c) {
            std::swap(c->m_suiv, c->m_prec);
            //on va au suivant, mais vu qu'on vient de swapper prec et suiv, on va au "pr�c�dent"
            c = c->m_prec;
        }
        std::swap(m_debut, m_apres.m_prec);
    }
}


#endif // listImpl_h
