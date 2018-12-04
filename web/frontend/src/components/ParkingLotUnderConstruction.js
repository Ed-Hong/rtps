import React, { Component } from 'react';
import { Rect, Stage, Layer, Text } from 'react-konva';
import Konva from 'konva';
import { render } from 'react-dom';

class ParkingLotUnderConstruction extends Component {

    render() {

        return (
            <img style={{flex:1, height: 500, width: 500}} 
            src={"https://www.jotajoti.info/wp-content/uploads/2018/08/under-construction_geek_man_01.png"} 
            alt={"under construction"}  />
        );

    };
};

export default ParkingLotUnderConstruction;

