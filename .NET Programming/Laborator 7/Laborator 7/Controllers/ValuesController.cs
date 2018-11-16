using System.Collections.Generic;
using BusinessLayer.Repository;
using DataLayer.CityData;
using Microsoft.AspNetCore.Mvc;

namespace Laborator_7.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        private readonly ICityRepository _repository;

        public ValuesController(ICityRepository repository)
        {
            _repository = repository;
        }

        // GET api/values
        [HttpGet]
        public ActionResult<List<City>> Get()
        {
            return _repository.GetCities();
        }

        // GET api/values/5
        [HttpGet("{id}")]
        public ActionResult<City> Get(int id)
        {
            return _repository.GetCity(id);
        }

        // POST api/values
        [HttpPost]
        public void Post([FromBody] City city)
        {
            _repository.CreateCity(city);
        }

        // PUT api/values/5
        [HttpPut("{id}")]
        public void Put(int id, [FromBody] City city)
        {
            _repository.EditCity(id, city);
        }

        // DELETE api/values/5
        [HttpDelete("{id}")]
        public void Delete(int id)
        {
            _repository.RemoveCity(id);
        }
    }
}
