package entity;

import javax.persistence.*;
import java.util.Objects;

/**
 * @author Victor Manoliu on 11-May-18
 */
@Entity
@Table(name = "CHARTS", schema = "STUDENT", catalog = "")
public class ChartsEntity {
    private long id;
    private long placement;

    @Id
    @Column(name = "ID")
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    @Basic
    @Column(name = "PLACEMENT")
    public long getPlacement() {
        return placement;
    }

    public void setPlacement(long placement) {
        this.placement = placement;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ChartsEntity that = (ChartsEntity) o;
        return id == that.id &&
                placement == that.placement;
    }

    @Override
    public int hashCode() {

        return Objects.hash(id, placement);
    }
}
