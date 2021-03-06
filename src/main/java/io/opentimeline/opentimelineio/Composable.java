// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

package io.opentimeline.opentimelineio;

import io.opentimeline.OTIONative;
import io.opentimeline.opentime.RationalTime;

/**
 * An object that can be composed by tracks.
 */
public class Composable extends SerializableObjectWithMetadata {

    protected Composable() {
    }

    Composable(OTIONative otioNative) {
        this.nativeManager = otioNative;
    }

    public Composable(String name, AnyDictionary metadata) {
        this.initObject(name, metadata);
    }

    public Composable(String name) {
        this.initObject(name, new AnyDictionary());
    }

    public Composable(AnyDictionary metadata) {
        this.initObject("", metadata);
    }

    public Composable(Composable.ComposableBuilder builder) {
        this.initObject(builder.name, builder.metadata);
    }

    private void initObject(String name, AnyDictionary metadata) {
        this.initialize(name, metadata);
        this.nativeManager.className = this.getClass().getCanonicalName();
    }

    private native void initialize(String name, AnyDictionary metadata);

    public static class ComposableBuilder {
        private String name = "";
        private AnyDictionary metadata = new AnyDictionary();

        public ComposableBuilder() {
        }

        public Composable.ComposableBuilder setName(String name) {
            this.name = name;
            return this;
        }

        public Composable.ComposableBuilder setMetadata(AnyDictionary metadata) {
            this.metadata = metadata;
            return this;
        }

        public Composable build() {
            return new Composable(this);
        }
    }

    /**
     * @return the visibility of the Composable. By default true.
     */
    public native boolean isVisible();

    /**
     * @return Return whether an Item is overlapping. By default false.
     */
    public native boolean isOverlapping();

    /**
     * @return the parent Composable, or null if this has no parent.
     */
    public native Composition parent();

    /**
     * @param errorStatus errorStatus to report in case this is not implemented in a sub-class.
     * @return the duration of the Composable object.
     */
    public native RationalTime getDuration(ErrorStatus errorStatus);

    @Override
    public String toString() {
        return this.getClass().getCanonicalName() +
                "(" +
                "name=" + this.getName() +
                ", metadata=" + this.getMetadata() +
                ")";
    }
}
