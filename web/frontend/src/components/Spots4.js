import React, { Component } from 'react';
import { Rect, Stage, Layer, Text } from 'react-konva';
import Konva from 'konva';
import { render } from 'react-dom';

class Spots4 extends Component {

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
            <Text x={50} y={10} text="camera 4"/>
            <Rect
                x={50}
                y={this.state.id*60-30}
                width={50}
                height={50}
                fill={"grey"}
                shadowBlur={5}
            />
            </>
        );

    };
};

export default Spots4;