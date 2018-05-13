package controller;

import entity.ArtistsEntity;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.util.List;

/**
 * @author Victor Manoliu on 09-May-18
 */
public class ArtistController {

    private EntityManagerFactory emf;

    public ArtistController(EntityManagerFactory emf) {
        this.emf = emf;
    }

    public void create(ArtistsEntity artist) {
        EntityManager em = emf.createEntityManager();
        em.getTransaction().begin();
        em.persist(artist);
        em.getTransaction().commit();
        em.close();
    }

    public ArtistsEntity findByName(String artistName) {
        EntityManager em = emf.createEntityManager();
        Query query = em.createQuery("select t from ARTISTS t where t.name=:name");
        List<ArtistsEntity> artists = query.setParameter("name", artistName).getResultList();
        em.close();
        return artists.isEmpty() ? null : artists.get(0);
    }

    public int getArtistId(String artistName) {
        EntityManager em = emf.createEntityManager();
        Query query = em.createQuery("select t.id from ARTISTS t where t.name=:name");
        List<Integer> artitsId = query.setParameter("name", artistName).getResultList();
        em.close();
        return artitsId.isEmpty() ? Integer.parseInt(null) : artitsId.get(0);
    }

}
