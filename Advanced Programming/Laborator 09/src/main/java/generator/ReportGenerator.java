package generator;

import db.Database;
import net.sf.dynamicreports.report.constant.HorizontalImageAlignment;
import net.sf.dynamicreports.report.exception.DRException;

import java.awt.*;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import static net.sf.dynamicreports.report.builder.DynamicReports.*;

/**
 * @author Victor Manoliu on 30-Apr-18
 */
public class ReportGenerator {

    public void generateHTMLRaport()
    {
        net.sf.dynamicreports.report.builder.style.StyleBuilder boldStyle = stl.style().bold();
        net.sf.dynamicreports.report.builder.style.StyleBuilder boldCenteredStyle = stl.style(boldStyle).setHorizontalImageAlignment(HorizontalImageAlignment.CENTER);
        net.sf.dynamicreports.report.builder.style.StyleBuilder columnTitleStyle = stl.style(boldCenteredStyle).setBorder(stl.pen1Point()).setBackgroundColor(Color.LIGHT_GRAY);
        String querryDataSource = "select distinct artists.name, artists.country, albums.name, count(artist_id) from albums join artists on albums.id = artists.id group by albums.name, albums.artist_id, artists.name, artists.country";

        try {
            report().columns(
                    col.column("Artist", "name", type.stringType()),
                    col.column("Country", "country", type.stringType()),
                    col.column("Album name", "name", type.stringType()),
                    col.column("Number of albums", "count(artist_id)", type.integerType())

            ).setColumnTitleStyle(columnTitleStyle).highlightDetailEvenRows().title(cmp.text("Report of artists and albums")).pageFooter(cmp.pageXofY())
                    .setDataSource(querryDataSource, Database.getConnection())
                    .toHtml(new FileOutputStream("report.html"))
                    .show();

        } catch (DRException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
