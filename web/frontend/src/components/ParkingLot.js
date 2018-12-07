import React, { Component } from 'react';
//import logo from './logo.svg';
//import './App.css';
import Spots1 from './Spots1';
import Spots2 from './Spots2';
import Spots3 from './Spots3';
import Spots4 from './Spots4';
import Spots5 from './Spots5';
import {BrowserRouter, Route, NavLink} from "react-router-dom";
import { Rect, Stage, Layer, Text} from 'react-konva';
import axios from 'axios';

class ParkingLot extends Component {

  constructor(props) {
    super(props);

    this.state = {
      parkingSpots1: null,
      
      parkingSpots2: [
        {id:1, status:0},
        {id:2, status:1},
        {id:3, status:1},
        {id:4, status:0},
        {id:5, status:0},
        {id:6, status:1},
        {id:7, status:0},
        {id:8, status:0},
        {id:9, status:0},
        {id:10, status:0}
      ],   
      parkingSpots3: [
        {id:1, status:0},
        {id:2, status:1},
        {id:3, status:1},
        {id:4, status:0},
        {id:5, status:0},
        {id:6, status:1},
        {id:7, status:0},
        {id:8, status:0},
        {id:9, status:0},
        {id:10, status:0}
      ],

      parkingSpots4: [
        {id:1, status:0},
        {id:2, status:1},
        {id:3, status:1},
        {id:4, status:0},
        {id:5, status:0},
        {id:6, status:1},
        {id:7, status:0},
        {id:8, status:0},
        {id:9, status:0},
        {id:10, status:0}
      ],

      parkingSpots5: [
        {id:1, status:0},
        {id:2, status:1},
        {id:3, status:1},
        {id:4, status:0},
        {id:5, status:0},
        {id:6, status:1},
        {id:7, status:0},
        {id:8, status:0},
        {id:9, status:0},
        {id:10, status:0}
      ]
    };
  }

  // async componentDidMount() {
  //   console.log("TEST TEST TEST TEST TEST TEST TEST TEST TEST");
  //   var self = this;
  //   axios.get('http://localhost:5000/spots')
  //     .then(function(response) {
  //       console.log("PROMISE FULFILLED !!!!!!!");
  //       console.log(response);
  //       self.setState({
  //         parkingSpots2: response.data,
  //       });
  //       console.log("STATE HAS BEEN SET !!!!!!!!!");
  //     })
  //     .catch(function (error) {
  //       console.log("error!!!!!");
  //       console.log(error);
  //     });
  // }

  async componentDidMount() {
    console.log("TEST TEST TEST TEST TEST TEST TEST TEST TEST");
    var self = this;
    axios.get('http://localhost:5000/spots')
      .then(function(response) {
        console.log("PROMISE FULFILLED !!!!!!!");
        console.log(response);
        self.setState({
          parkingSpots1: response.data,
        });
        console.log("STATE HAS BEEN SET !!!!!!!!!");
      })
      .catch(function (error) {
        console.log("error!!!!!");
        console.log(error);
      });
  }

  render() {

    //{this.forceUpdate()}
    return (
      // <div className="ParkingLot" style={{backgroundColor: "#d1e0e0"}}>
      //<body onload="timer = setTimeout('auto_reload()',10000);">
      <>
      <div>
      <head>
        <meta http-equiv="refresh" content="10"></meta>
      </head>
      </div>
      <Stage width={window.innerWidth} height = {window.innerHeight} >
        <Layer>
          {
            this.state.parkingSpots1 && this.state.parkingSpots1.map((i) => {
              return <Spots1 Id = {i.id} Status = {i.status} />
            })
          }
          { 
            this.state.parkingSpots2 && this.state.parkingSpots2.map((i) => {
              return <Spots2 Id = {i.id} Status = {i.status} />
            })
          }

          {
            this.state.parkingSpots3.map((i) => {
              return <Spots3 Id = {i.id} Status = {i.status} />
            })
          }

          {
            this.state.parkingSpots4.map((i) => {
              return <Spots4 Id = {i.id} Status = {i.status} />
            })
          }

          {
            this.state.parkingSpots5.map((i) => {
              return <Spots5 Id = {i.id} Status = {i.status} />
            })
          }
          {/* //{this.forceUpdate()} */}
        </Layer>
      </Stage>
      </>
    
      
      
   
    );
  }
}

export default ParkingLot;
