// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

package io.opentimeline.opentimelineio;

import io.opentimeline.OTIONative;
import io.opentimeline.opentime.TimeRange;

import java.util.stream.Stream;

/**
 * Contains a media reference and a trim on that media reference.
 */
public class Clip extends Item {

    protected Clip() {
    }

    Clip(OTIONative otioNative) {
        this.nativeManager = otioNative;
    }

    public Clip(
            String name,
            MediaReference mediaReference,
            TimeRange sourceRange,
            AnyDictionary metadata) {
        this.initObject(
                name,
                mediaReference,
                sourceRange,
                metadata);
    }

    public Clip(Clip.ClipBuilder builder) {
        this.initObject(
                builder.name,
                builder.mediaReference,
                builder.sourceRange,
                builder.metadata
        );
    }

    private void initObject(String name,
                            MediaReference mediaReference,
                            TimeRange sourceRange,
                            AnyDictionary metadata) {
        this.initialize(
                name,
                mediaReference,
                sourceRange,
                metadata);
        this.nativeManager.className = this.getClass().getCanonicalName();
    }

    private native void initialize(String name,
                                   MediaReference mediaReference,
                                   TimeRange sourceRange,
                                   AnyDictionary metadata);

    public static class ClipBuilder {
        private String name = "";
        private MediaReference mediaReference = null;
        private TimeRange sourceRange = null;
        private AnyDictionary metadata = new AnyDictionary();

        public ClipBuilder() {
        }

        public Clip.ClipBuilder setName(String name) {
            this.name = name;
            return this;
        }

        public Clip.ClipBuilder setMediaReference(MediaReference mediaReference) {
            this.mediaReference = mediaReference;
            return this;
        }

        public Clip.ClipBuilder setSourceRange(TimeRange sourceRange) {
            this.sourceRange = sourceRange;
            return this;
        }

        public Clip.ClipBuilder setMetadata(AnyDictionary metadata) {
            this.metadata = metadata;
            return this;
        }

        public Clip build() {
            return new Clip(this);
        }
    }

    public native void setMediaReference(MediaReference mediaReference);

    public native MediaReference getMediaReference();

    public native TimeRange getAvailableRange(ErrorStatus errorStatus);

    public Stream<Clip> eachClip() {
        return Stream.of(this);
    }

    @Override
    public String toString() {
        return this.getClass().getCanonicalName() + "" +
                "(" +
                "name=" + this.getName() +
                ", mediaReference=" + this.getMediaReference() +
                ", sourceRange=" + this.getSourceRange() +
                ", metadata=" + this.getMetadata() +
                ")";
    }
}
