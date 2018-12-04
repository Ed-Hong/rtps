import React, { Component } from 'react';
import { Rect, Stage, Layer, Text } from 'react-konva';
import Konva from 'konva';
import { render } from 'react-dom';

class Spots5 extends Component {

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
            <Text x={400} y={560} text="camera 5"/>
            <Rect
                x={this.state.id*60+100}
                y={580}
                width={50}
                height={50}
                fill={"grey"}
                shadowBlur={5}
            />
            </>
        );

    };
};

export default Spots5;

