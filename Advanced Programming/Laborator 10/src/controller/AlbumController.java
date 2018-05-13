package controller;

import entity.AlbumsEntity;
import entity.ArtistsEntity;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.util.List;

/**
 * @author Victor Manoliu on 09-May-18
 */
public class AlbumController {

    private EntityManagerFactory emf;

    public AlbumController(EntityManagerFactory emf)
    {
        this.emf = emf;
    }

    public void create(AlbumsEntity albumsEntity) {
        EntityManager em = emf.createEntityManager();
        em.getTransaction().begin();
        em.persist(albumsEntity);
        em.getTransaction().commit();
        em.close();
    }

    public AlbumsEntity findByName(String albumName) {
        EntityManager em = emf.createEntityManager();
        Query query = em.createQuery("select t from Albums t where t.name=:name");
        List<AlbumsEntity> albums = query.setParameter("name", albumName).getResultList();
        em.close();
        return albums.isEmpty() ? null : albums.get(0);
    }

    public List<AlbumsEntity> listByArtist(ArtistsEntity artistsEntity)
    {
        EntityManager em = emf.createEntityManager();
        Query query = em.createQuery("select t from Albums t where t.id=:id");
        List<AlbumsEntity> albums = query.setParameter("id", artistsEntity.getId()).getResultList();
        em.close();
        return albums;
    }
}
