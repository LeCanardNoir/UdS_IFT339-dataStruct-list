//
//  listImpl.h
//
//  Auteur : Jean Goulet
//  Copyleft  2017 UdeS
//
//  Modifie par : Vincent Ducharme, Automne 2022
//
//  Devoir fait par
//     Coéquipier 1 : Bruno Pouliot
//     Coéquipier 2 : Gabriel Dumont-Hétu

#ifndef listImpl_h
#define listImpl_h

//////////////////////////////////////////////////////////////
//TODO: fonctions generatrices privees
//////////////////////////////////////////////////////////////

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::insert(cellule* c, const TYPE& VAL)
{
    cellule* nouv = new cellule(TYPE());
    nouv->m_contenu = VAL;
    nouv->m_prec = c->m_prec;
    c->m_prec = nouv;
    nouv->m_suiv = c;
    if (nouv->m_prec) {
        nouv->m_prec->m_suiv = nouv;
    }
    else {
        m_debut = nouv;
    }
    m_size++;

    return nouv;
}

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::erase(cellule* c)
{
    if (size() > 0) {
        c->m_suiv->m_prec = c->m_prec;
        if(c->m_prec)
            c->m_prec->m_suiv = c->m_suiv;
        else
            m_debut = c->m_suiv;

        m_size--;
    }

    cellule* tmp = c->m_suiv;
    delete c;
    c = nullptr;
    return tmp;
    
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
    TYPE& operator*()const { return m_pointeur->m_contenu; }
    TYPE* operator->()const { return &(m_pointeur->m_contenu); }

    reverse_iterator& operator++() {
        // i++
        m_pointeur = m_pointeur->m_prec;
        return *this;
    };

    reverse_iterator operator++(int) {
        // ++i
        reverse_iterator rev_it(*this);
        operator++();
        return rev_it;
    };

    reverse_iterator& operator--() {
        // --i
        m_pointeur = m_pointeur->m_suiv;
        return *this;
    };

    reverse_iterator operator--(int) {
        // i--
        reverse_iterator rev_it(*this);
        operator--();
        return rev_it;
    };

    bool operator==(const reverse_iterator&droite)const {
        return m_pointeur == droite.m_pointeur;
    };

    bool operator!=(const reverse_iterator&droite)const {
        return !(*this == droite);
    };
};

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rbegin()
{
    return reverse_iterator(m_apres.m_prec);
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rend()
{
    return reverse_iterator(m_debut->m_prec);
}


///////////////////////////////////////////////////////////
//affectateur
///////////////////////////////////////////////////////////

template <typename TYPE>
list<TYPE>& list<TYPE>::operator=(const list<TYPE>& droite)
{
    // TODO: operator=
    for (iterator it = begin(); it != end(); it++)
        erase(it);

    /*m_apres = TYPE();
    m_debut = &m_apres;
    m_size = 0;*/

    for (const auto& x : droite)
        push_back(x);

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
            //on va au suivant, mais vu qu'on vient de swapper prec et suiv, on va au "précédent"
            c = c->m_prec;
        }
        std::swap(m_debut, m_apres.m_prec);
    }
}


#endif // listImpl_h
