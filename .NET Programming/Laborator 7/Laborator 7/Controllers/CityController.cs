using System.Collections.Generic;
using BusinessLayer.Repository;
using DataLayer.CityData;
using Microsoft.AspNetCore.Mvc;

namespace Laborator_7.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CityController : ControllerBase
    {
        private readonly ICityRepository _repository;

        public CityController(ICityRepository repository)
        {
            _repository = repository;
        }

        // GET: api/City
        [HttpGet]
        public ActionResult<List<City>> Get()
        {
            return _repository.GetCities();
        }

        //GET: api/City/5
        [HttpGet("{id}")]
        public ActionResult<City> Get(int id)
        {
            return _repository.GetCity(id);
        }

        // POST: api/City
        [HttpPost]
        public void Post([FromBody] City city)
        {
            _repository.CreateCity(city);
        }

        // PUT: api/City/5
        [HttpPut("{id}")]
        public void Put(int id, [FromBody] City city)
        {
            _repository.EditCity(id, city);
        }

        // DELETE: api/ApiWithActions/5
        [HttpDelete("{id}")]
        public void Delete(int id)
        {
            _repository.RemoveCity(id);
        }
    }
}
