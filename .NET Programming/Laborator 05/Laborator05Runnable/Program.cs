using Laborator_05.CityData;
using Laborator_05.Controller;
using Laborator_05.PoiData;

namespace Laborator05Runnable
{
    class Program
    {
        public static void Main()
        {
            CityController cityController = new CityController();
            PoiController poiController = new PoiController();
            cityController.CreateCity(new City(2, "Roman", "Unde plm e Roman", 169.0, 169));
            cityController.GetCities();
            poiController.AddPoi(new Poi(1,"What in oblivion is POI?","Guess i'll die",1));
            poiController.GetPois();
        }
    }

}
