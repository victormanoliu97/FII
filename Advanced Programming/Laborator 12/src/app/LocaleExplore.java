package app;

import com.sun.java.accessibility.util.Translator;

import java.text.DateFormat;
import java.text.DateFormatSymbols;
import java.text.MessageFormat;
import java.util.*;

/**
 * @author Victor Manoliu on 21-May-18
 */
public class LocaleExplore {

    private final String baseName = "Messages";
    private Locale locale;
    private ResourceBundle resourceBundle;


    public void run() {
        setLocale("en-US");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print(message("prompt"));
            String command = scanner.nextLine();
            if (command.equals("exit")) break;
            String[] params = command.trim().split("\\s+");
            switch (params[0]) {
                case "locales" : displayLocales(); break;
                case "set"     : setLocale(params[1]); break;
                case "info"    : localeInfo(); break;
                default        : System.out.println(message("invalid"));
            }
        }
    }
    private String message(String key, String ... arguments) {
        String pattern = resourceBundle.getString(key);
        String message = new MessageFormat(pattern).format(arguments);
        return message;
    }

    private void setLocale(String languageTag) {
        this.locale = Locale.forLanguageTag(languageTag);
        this.resourceBundle = ResourceBundle.getBundle(baseName, locale);
        message("locale.set", languageTag);
    }

    private void displayLocales() {
        message("locales");
        System.out.println(Locale.getDefault());
    }
    private void localeInfo() {
        message("locale.set");
        System.out.println("Country:" + " " + locale.getDisplayCountry(locale));
        System.out.println("Language:" + " " + locale.getDisplayLanguage());
        System.out.println("Currency:" + " " + Currency.getInstance(locale).getCurrencyCode());

        String[] weekDays = DateFormatSymbols.getInstance(locale).getWeekdays();
        System.out.println("Week days:" + " " + Arrays.toString(weekDays).replace("[","").replace("]",""));

        String[] monthsOfYear = DateFormatSymbols.getInstance(locale).getMonths();
        System.out.println("Months:" + " " + Arrays.toString(monthsOfYear).replace("[", "").replace("]", ""));

        System.out.println("Today:" + " " + DateFormat.getDateInstance(DateFormat.LONG, locale).format(new Date()));

    }
    public static void main(String args[]) {
        new LocaleExplore().run();
    }
}
