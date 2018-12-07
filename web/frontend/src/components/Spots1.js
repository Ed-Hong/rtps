import React, { Component } from 'react';
import { Rect, Stage, Layer, Text } from 'react-konva';
import Konva from 'konva';
import { render } from 'react-dom';

class Spots1 extends Component {

    constructor(props) {
        super(props);

        this.state = {
            id: props.Id,
            color: (props.Status) ? 'green' : 'red',
            text: (props.Status) ? '' : 'X'
        };
    };


    render() {

        return (
            <>
            <Text x={430} y={10} text="camera 1"/>
            <Rect
                x={this.state.id*60+100}
                y={30}
                width={50}
                height={50}
                fill={this.state.color}
                shadowBlur={5}
            />
            <Text x={this.state.id*60+100+2}
                y={30-7}
                text={this.state.text}
                fontSize="67" />
            </>
            
        );

    };
};

export default Spots1;

